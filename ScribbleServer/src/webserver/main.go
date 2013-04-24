package main

import (
	"flag"
	"log"
	"net/http"
	"os/exec"
	"fmt"
	"os"
)

var addr = flag.String("addr", ":80", "WebServer Service")
var path = ""

func writeSource(source string) string {

	fo, err := os.Create("temp.scribble")

	if err != nil {
		return ""
	}

	fo.Write([]byte(source))

	fo.Close()

	return "temp"
}

func pageHandler(c http.ResponseWriter, req *http.Request) {
	fmt.Printf("Handle %s\n", req.FormValue("source"))

	c.Header().Set("Access-Control-Allow-Origin", "*")


	out, err := exec.Command(path, writeSource(req.FormValue("source"))).Output()

	if err != nil {
		c.Write([]byte("Error:"+err.Error()+"\n"+ string(out)))
	} else {
		c.Write([]byte(out))
	}
}

func main() {

	directoryFlag := flag.String("path", "./", "The path to the scribble interpretor")
	flag.Parse()
	path = *directoryFlag

	http.HandleFunc("/run", pageHandler)

	if err := http.ListenAndServe(*addr, nil); err != nil {
		log.Fatal("ListenAndServe:", err)
	}
}