package main

import "fmt"

type A struct {
	I int
	S string
}

func getA(a *A) {
	a.I = 100
	a.S = "sssss"
}

func testF() {
	var a A
	a.I = 111
	a.S = "abc"
	fmt.Println(a)
	//getA(a)
	getA(&a)
	fmt.Println(a)
}

func testDefer() {
	defer fmt.Println("1")
	defer fmt.Println("2")

	return

	defer fmt.Println("3")
}

func chanWork(ch chan int, i int) {
	ch <- i
}

func testChan() {
	ch := make(chan int)
	defer close(ch)
	for i := 0; i < 10; i++ {
		go chanWork(ch, i)
	}

	for i := 0; i < 10; i++ {
		r := <-ch
		fmt.Println(i, r)
	}

}

func modSlice(sl *[]int) {
	*sl = append(*sl, 4)
}

func modSlice2(sl []int) {
	sl = append(sl, 5)
}

func testSlice() {
	sl := []int{1, 2, 3}

	modSlice2(sl)
	modSlice(&sl)
	fmt.Println(sl)
}

func modMap(m map[string]string) {
	m["a"] = "1"
}

func testMap() {
	m := map[string]string{}
	m["b"] = "2"

	v, ok := m["c"]
	if ok {
		fmt.Println(v)
	}
	d := m["d"]
	fmt.Println(d)

	modMap(m)
	fmt.Println(m)
}

func testRange() {
	l := []int{1, 2, 3}

	for i, a := range l {
		fmt.Println(a)
		a = i * 100
		//l[i] = a
	}

	fmt.Println(l)
}

func testSlice2() {
	l := []int{1, 2, 3, 4, 5, 6}

	ll := l
	fmt.Println(ll)
	l = l[:0]
	l = append(l, 100)
	fmt.Println(l)
	fmt.Println(ll)
}

func testGo3(i int) {
	fmt.Println(i)
}

func testGo2() {
	go testGo3(1)
	go testGo3(2)
	go testGo3(3)
}

func testGo() {
	go testGo2()

	for true {

	}
}

func main() {
	fmt.Println("Hello, Go!")

	//testF()
	//testDefer()
	//testChan()
	//testSlice()
	//testMap()
	//testRange()
	//testSlice2()
	testGo()

}
