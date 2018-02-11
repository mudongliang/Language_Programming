package main

import (
	"fmt"
)

func main() {
	var a []int
	printSlice("a", a)

	//append works on nil slices , maybe my go version is different from the golang website!
	//golang : a len=1 cap=2 , mine : a len=1 cap=1
	a = append(a, 0)
	printSlice("a", a)

	//the slice grows as needed.
	a = append(a, 1)
	printSlice("a", a)

	//we can add more than one element at a time.
	a = append(a, 2, 3)
	printSlice("a", a)

	/*
		a := make([]int, 5)
		printSlice("a", a)
		b := make([]int, 0, 5)
		printSlice("b", b)
		c := b[:2]
		printSlice("c", c)
		d := c[1:]
		printSlice("d", d)
	*/
}

func printSlice(s string, x []int) {
	fmt.Printf("%s len=%d cap=%d %v\n", s, len(x), cap(x), x)
}
