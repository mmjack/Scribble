func IsSorted(n : array(int)) : bool {

	for var i := 1; i < len(n); i++ do {

		if n[i] < n[i-1] then
			return false;

	}

	return true;
}