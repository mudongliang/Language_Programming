package main

import (
	"fmt"
	"math"
)

func MySqrt(x float64) float64 {
	z := 1.0
	var tmp float64
	for i := 0; i < 10; i++ {
		tmp = z*z - x
		z = z - tmp/(2*z)
	}
	return z
}

func main() {
	//var i int = 2
	//fmt.Println(MySqrt(float64(i))) another notice : explicit type conversations!
	fmt.Println(math.Sqrt(2))
	fmt.Println(MySqrt(2))
}
