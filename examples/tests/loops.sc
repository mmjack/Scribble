package sys := import("sys");
package test := import("test");

func ForTest() {
 var iter := 0;
 for var i := 0; i < 100; i++ do {
  for var j := 0; j < 100; j++ do {
   iter++;
  }
 }
 test.Assert(iter, 10000, "Iter is not correct. Loops test has failed on a for loop");
}

func WhileTest() {
 var i := 0;
 var j := 0;
 
 while i < 100 do {
  j := 0;
  while j < 100 do {
   iter++;
   j++;
  }
  i++;
 }

 test.Assert(iter, 10000, "Iter is not correct. Loops test has failed on a while loop");
}

func ForBetweenTest() {
 for var k between 0 and 1000 do {
 }
 test.Assert(k, 999, "k is not correct");
}

func Test() {
 WhileTest();
 ForTest();
 ForBetweenTest();
}
