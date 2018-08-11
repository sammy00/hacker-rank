package main_test

import (
	"reflect"
	"testing"
)

// Complete the rotLeft function below.
func rotLeft(a []int32, d int32) []int32 {
	ell := len(a)
	if (0 == ell) || (0 == d) {
		return a
	}

	dd := int(d) % ell

	// reverse a[0],...,a[dd-1] as a[dd-1],...,a[0]
	for i, j := 0, dd-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}

	// reverse a[dd], ..., a[ell-1] as a[ell-1], ..., a[dd]
	for i, j := dd, ell-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}

	// reverse a[dd-1], ..., a[0], a[ell-1], ..., a[dd]
	// as a[dd], ..., a[ell-1], a[0], ..., a[dd-1]
	for i, j := 0, ell-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}

	return a
}

func TestRotLeft(t *testing.T) {
	testCases := []struct {
		//n      int32
		d      int32
		a      []int32
		expect []int32
	}{
		{
			13,
			[]int32{33, 47, 70, 37, 8, 53, 13, 93, 71, 72, 51, 100, 60, 87, 97},
			[]int32{87, 97, 33, 47, 70, 37, 8, 53, 13, 93, 71, 72, 51, 100, 60},
		},
	}

	for i, c := range testCases {
		b := rotLeft(c.a, c.d)
		if !reflect.DeepEqual(b, c.expect) {
			t.Fatalf("invalid output #%d: got %v, expect %v", i, b, c.expect)
		}
	}
}
