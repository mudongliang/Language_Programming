package main

import (
	"fmt"
)

func main() {
	v := 42           // int
	s := "string"     // string
	b := false        // bool
	f := 3.142        // float64
	g := 0.867 + 0.5i // complex128
	fmt.Printf("v is of type %T\n", v)
	fmt.Printf("s is of type %T\n", s)
	fmt.Printf("b is of type %T\n", b)
	fmt.Printf("f is of type %T\n", f)
	fmt.Printf("g is of type %T\n", g)
}
