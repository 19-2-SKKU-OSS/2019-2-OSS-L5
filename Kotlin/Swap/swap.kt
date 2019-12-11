fun swap( x : Int, y : Int ) {
	println("x: $x")
	println("y: $y")

	var tmp : Int = x
	x = y
	y = tmp

        println("x: $x")
        println("y: $y")
}

fun main( args : Array<String> ) {
	swap( 3, 5 )
}
