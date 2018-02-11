package main

import (
	"fmt"
)

func fibonacci() func(int) int  {
	suma := 1
	sumb := 1
	return func(x int) int {
		 for i := 1; i < x; i++ {
			result := suma + sumb	
			sumb = suma
			suma = result
		 }
		return suma
	}
}

func main() {
	for i := 0; i < 10; i++ {
		f := fibonacci()
		fmt.Println(f(i))
	}
}


