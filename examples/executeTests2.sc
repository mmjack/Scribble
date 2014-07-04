/**
 * Scribble tests execution file
 * Copyright (c) Blake Loring 2013
 */

package loopsTest := import("loops");
package logicalTest := import("logical");
package variablesTest := import("variables");
package recursionTest := import("recursion");
package arraysTest := import("arrays");
package primesTest := import("primes");
package sortsTest := import("sorts");
package floatsTest := import("floats");
package mathTest := import("math");
package structTest := import("structures");
package structQs := import("structQuicksortTest");
package refEqTest := import("refEqualityTest");
package listTest := import("LinkedList");

package sys := import("sys");
package console := import("console");

/**
 * The main function executes all of the Scribble unit tests.
 */
 
func main() {

 loopsTest.Test();
 arraysTest.Test();
 variablesTest.Test();
 recursionTest.Test();
 primesTest.Test();
 logicalTest.Test();
 sortsTest.Test();
 floatsTest.Test();
 mathTest.Test();
 structTest.Test();
 structQs.Test();
 refEqTest.Test();
 listTest.Test();

}
