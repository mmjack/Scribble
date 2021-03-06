/**
 * Package contains functions to populate a list with pre sorted and reverse order arrays.
 *
 * Copyright (c) Blake Loring 2013
 */
package sys     := import("sys"),
        console := import("console");

/**
 * Populate the given array with reverse order values
 */
func PopulateWorstCase(list:array(int)) -> array(int) {

	for var i between 0 and len(list) do {
		list[i] := len(list) - i;
	}

	return list;
}

/**
 * Populate the specified array with a pre sorted list
 */
func PopulateBestCase(list:array(int)) -> array(int) {

	for var i between 0 and len(list) do {
		list[i] := i;
	}

	return list;
}

/**
 * Print out the array of integers from left to right
 */
func PrintList(list:array(int)) {

	for var i between 0 and len(list) do {
		console.Log( sys.String(list[i]) );
		console.Log(" ");
	}

	console.Log("\n");
}
