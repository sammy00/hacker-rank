package main

import (
	"bufio"
	"fmt"
	"io"
	"strings"
)

// Complete the rotLeft function below.
func rotLeft(a []int32, d int32) []int32 {
	ell := int32(len(a))
	if (0 == ell) || (0 == d) {
		return a
	}

	d %= ell

	for i := int32(0); i < ell; i++ {
		j := i + d
		if j >= ell {
			j = ell - 1
		}

		a[i], a[j] = a[j], a[i]
	}

	return a
}

func main() {
	var n, d int32

	fmt.Scanf("%d %d", &n, &d)
	//fmt.Println(n, d)

	a := make([]int32, n)
	for i := range a {
		fmt.Scanf("%d", &a[i])
	}

	fmt.Println("a=", a)

	b := rotLeft(a, d)
	fmt.Println("b=", b)
	/*
		reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

		stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
		checkError(err)

		defer stdout.Close()

		writer := bufio.NewWriterSize(stdout, 1024*1024)

		nd := strings.Split(readLine(reader), " ")

		nTemp, err := strconv.ParseInt(nd[0], 10, 64)
		checkError(err)
		n := int32(nTemp)

		dTemp, err := strconv.ParseInt(nd[1], 10, 64)
		checkError(err)
		d := int32(dTemp)

		aTemp := strings.Split(readLine(reader), " ")

		var a []int32

		for i := 0; i < int(n); i++ {
			aItemTemp, err := strconv.ParseInt(aTemp[i], 10, 64)
			checkError(err)
			aItem := int32(aItemTemp)
			a = append(a, aItem)
		}

		result := rotLeft(a, d)

		for i, resultItem := range result {
			fmt.Fprintf(writer, "%d", resultItem)

			if i != len(result)-1 {
				fmt.Fprintf(writer, " ")
			}
		}

		fmt.Fprintf(writer, "\n")

		writer.Flush()
	*/
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err != nil {
		panic(err)
	}
}
