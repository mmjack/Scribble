package test := import("test");

func simple(n : int) : int {

	if n = 0 then 
		return 0;
	
	return 1 + simple(n-1);
}

func even(n : int) : bool {
	
	if n = 0 then 
		return true;
	
	return odd(n-1);
}

func odd(n : int) : bool {
	
	if n = 0 then 
		return false;
	
	return even(n-1);
}

func Test() {

	if simple(1000) != 1000 then {
		test.Fatal("Simple(1000) test failed");
	}

	if even(1000) = false then {
		test.Fatal("even(1000) test failed");
	}

	if odd(1000) = true then {
		test.Fatal("odd(1000) test failed");
	}

}