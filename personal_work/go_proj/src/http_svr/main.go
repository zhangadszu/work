package main

import(
	"io"
	"net/http"
)

func helloHandler(w http.ResponseWriter, req *http.Request) {
	io.WriteString(w, "hello, world!\n")
}

func helloGoHandler(w http.ResponseWriter, req *http.Request) {
	io.WriteString(w, "hello, go!\n")
}

func main() {
	http.HandleFunc("/helloworld", helloHandler)
	http.HandleFunc("/hellogo", helloGoHandler)
	http.ListenAndServe(":8080", nil)
}