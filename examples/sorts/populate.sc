package sys := import("sys");

func PopulateWorstCase( list : array(int)) : array(int) {

	for var i := 0; i < len(list); i++ do {
		list[i] := len(list) - i;
	}

	return list;
}

func PopulateBestCase(list : array(int)) : array(int) {

	for var i := 0; i < len(list); i++ do {
		list[i] := i;
	}

	return list;
}

func PrintList(list : array(int)) {

	for var i := 0; i < len(list); i++ do {
		sys.Write( sys.String(list[i]) );
		sys.Write(" ");
	}
	
	sys.Write("\n");
}