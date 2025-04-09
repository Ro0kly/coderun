package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var in *bufio.Reader
	var out *bufio.Writer
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var num int
	fmt.Fscan(in, &num)

	slise := make([]string, num)
	for i := range slise {
		fmt.Fscan(in, &slise[i])
	}

	for index, str := range slise {
		if len(str) == 0 {
			fmt.Println(index, " NO")
			continue
		}
		if str[0] != str[len(str)-1] {
			fmt.Println(index, " NO")
			continue
		}
		flag := true
		first := str[0]
		for i := 1; i < len(str)-1; i++ {
			if str[i] != first && str[i-1] != str[i+1] {
				flag = false
				break
			}
		}
		if flag {
			fmt.Println(index, " YES")
		} else {
			fmt.Println(index, " NO")
		}
	}
}
