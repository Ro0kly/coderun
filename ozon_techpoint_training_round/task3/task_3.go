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

	var allNum int
	fmt.Fscan(in, &allNum)
	// fmt.Println("allNum: ", allNum)
	allArr := make([][]string, allNum)

	for i := range allArr {
		// fmt.Println(i)
		var num int
		fmt.Fscan(in, &num)
		allArr[i] = make([]string, num)
		for j := range allArr[i] {
			fmt.Fscan(in, &allArr[i][j])
		}
	}
	// fmt.Println("allArr count: ", len(allArr))

	for _, arr := range allArr {
		res := 0
		for k := range arr {
			str1 := arr[k]
			// fmt.Println("str1 index", k)
			for i := k + 1; i < len(arr); i++ {
				str2 := arr[i]
				// fmt.Println("compare str1 index and str2 index: ", k, " and ", i)

				if (len(str1) == 1 || len(str2) == 1) && str1[0] != str2[0] {
					// fmt.Println("here 0: ", str1[0], " - ", str2[0])
					// fmt.Println(str1[0] == str2[0])
					// fmt.Println(len(str1) == 1 || len(str2) == 1 && str1[0] != str2[0])
					continue
				} else if len(str1) == 1 && len(str2) == 1 && str1[0] == str2[0] {
					// fmt.Println("here 1")
					res += 1
					continue
				}
				even := true
				odd := true
				length := min(len(str1), len(str2))

				for j := 0; j < length && (even || odd); j++ {
					// fmt.Println("loop")
					if j%2 == 0 && str1[j] != str2[j] {
						even = false
					}
					if j%2 != 0 && str1[j] != str2[j] {
						odd = false
					}
				}
				if even || odd {
					res += 1
				}
			}
		}
		fmt.Println(res)
		// fmt.Println("RESULT: ", res)
	}
}
