package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	//argc := len(os.Args)

	f1, err := os.Open(os.Args[1])
	if err != nil {
		fmt.Println("1 unexpected")
		return
	}
	defer f1.Close()

	f2, err := os.Open(os.Args[2])
	if err != nil {
		fmt.Println("2 unexpected")
		return
	}
	defer f2.Close()

	f3, err := os.OpenFile(os.Args[3], os.O_WRONLY|os.O_CREATE|os.O_TRUNC, 0666)
	if err != nil {
		fmt.Println("3 unexpected")
		return
	}
	defer f3.Close()

	sk1, _ := strconv.Atoi(os.Args[4])
	sk2, _ := strconv.Atoi(os.Args[5])

	ir1 := bufio.NewReader(f1)
	ir1.Discard(sk1)
	ir2 := bufio.NewReader(f2)
	ir2.Discard(sk2)

	buffer := bufio.NewWriter(f3)
	defer buffer.Flush()

	a := make([]byte, 1)
	b := make([]byte, 1)

	for {
		n, _ := ir1.Read(a)
		if n != 1 {
			break
		}
		n, _ = ir2.Read(b)
		if n != 1 {
			break
		}

		err := buffer.WriteByte(a[0] ^ b[0])
		if err != nil {
			fmt.Println("4 unexpected")
			break
		}
	}
}
