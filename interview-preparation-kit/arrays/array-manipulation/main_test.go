package manipulation_test

import (
	"testing"
)

// Complete the arrayManipulation function below.
func arrayManipulation(n int32, queries [][]int32) int64 {
	// arr[i] records the increment of the i-the element w.r.t its left
	arr := make([]int64, n+2)

	for _, q := range queries {
		arr[q[0]] += int64(q[2])
		arr[q[1]+1] -= int64(q[2])
	}

	max := int64(-1 << 63)
	var sum int64
	for _, a := range arr {
		sum += a
		if sum > max {
			max = sum
		}
	}

	return max
}

func TestArrayManipulation(t *testing.T) {
	testCases := []struct {
		n       int32
		queries [][]int32
		expect  int64
	}{
		{5,
			[][]int32{
				[]int32{1, 2, 100},
				[]int32{2, 5, 100},
				[]int32{3, 4, 100},
			},
			200,
		}, {
			10,
			[][]int32{
				[]int32{1, 5, 3},
				[]int32{4, 8, 7},
				[]int32{6, 9, 1},
			},
			10,
		}, {
			10,
			[][]int32{
				[]int32{2, 6, 8},
				[]int32{3, 5, 7},
				[]int32{1, 8, 1},
				[]int32{5, 9, 15},
			},
			31,
		},
	}

	for i, c := range testCases {
		got := arrayManipulation(c.n, c.queries)
		if got != c.expect {
			t.Errorf("invalid output[%d]: got %d, expect %d", i, got, c.expect)
		}
	}
}
