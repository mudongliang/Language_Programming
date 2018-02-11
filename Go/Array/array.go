package main

import (
	"fmt"
)

func main() {
	var a [2]string
	a[0] = "string"
	a[1] = "array"
	fmt.Println(a[0], a[1])
	fmt.Println(a)
}
