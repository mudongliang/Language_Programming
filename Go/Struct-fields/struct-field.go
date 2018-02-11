package main

import (
	"fmt"
)

type Vertex struct {
	X int
	Y int
}

func (v Vertex) String() string {
	return fmt.Sprintf("X = %d,Y = %d",v.X,v.Y)
}

func main() {
	v := Vertex{1,2}
	v.X = 4
	fmt.Println(v)
}

