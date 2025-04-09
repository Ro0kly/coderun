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
	var allBanks = make([][]map[string][]float32, num)
	for i := 0; i < num; i++ {
		var banks = make([]map[string][]float32, 3)
		var trArr = [6]string{"r->d", "r->e", "d->r", "d->e", "e->r", "e->d"}
		for j := range banks {
			dict := make(map[string][]float32, 6)
			for _, str := range trArr {
				var a, b float32
				fmt.Fscan(in, &a, &b)
				dict[str] = []float32{a, b}
			}
			banks[j] = dict
		}
		allBanks[i] = banks
	}

	for _, v := range allBanks {
		var res float32
		method('r', 1, v, []int{0, 1, 2}, 0, &res)
		method('r', 1, v, []int{0, 2, 1}, 0, &res)
		method('r', 1, v, []int{1, 2, 0}, 0, &res)
		method('r', 1, v, []int{1, 0, 2}, 0, &res)
		method('r', 1, v, []int{2, 1, 0}, 0, &res)
		method('r', 1, v, []int{2, 0, 1}, 0, &res)
		// fmt.Println("BANK NUMBER: ", i, " ", "RESULT: ", res)
		fmt.Println(res)
	}

	// for i, v := range arr {
	// fmt.Println(i, ". ", v)
	// }
}

//	for _, b := range banks {
//		fmt.Println("count: ", len(b))
//		for k, v := range b {
//			fmt.Println(k, " ", v)
//		}
//	}
func method(curType byte, curVal float32, banks []map[string][]float32, bankQueue []int, bankIndex int, res *float32) {
	var m map[string][]float32 = banks[bankQueue[bankIndex]]
	// println("Bank index: ", bankIndex)
	for k, v := range m {
		if k[0] == curType {
			nextType := k[len(k)-1]
			nextVal := curVal * (v[1] / v[0])
			if nextType == 'd' && nextVal > *res {
				*res = nextVal
				// fmt.Println(*res, " > ", curVal)
				// fmt.Println(k, " ", v[0], v[1], " | ", curVal, string(curType), " to ", nextVal, string(nextType))
			}
			if bankIndex != len(banks)-1 {
				method(nextType, nextVal, banks, bankQueue, bankIndex+1, res)
			}
		}
	}
}

// bankA := make(map[string][]float32)
// bankA["r->d"] = []float32{100, 1}
// bankA["r->e"] = []float32{100, 1}
// bankA["d->r"] = []float32{1, 100}
// bankA["d->e"] = []float32{3, 2}
// bankA["e->r"] = []float32{1, 100}
// bankA["e->d"] = []float32{2, 3}
//
// bankB := make(map[string][]float32)
// bankB["r->d"] = []float32{100, 1}
// bankB["r->e"] = []float32{100, 1}
// bankB["d->r"] = []float32{1, 100}
// bankB["d->e"] = []float32{3, 2}
// bankB["e->r"] = []float32{1, 100}
// bankB["e->d"] = []float32{2, 3}
//
// banks[0] = bankA
// banks[1] = bankB
