fun Swap( data : IntArray, i : Int, j : Int ){
	var tmp : Int = data[i]
	data[i] = data[j]
	data[j] = tmp
}

fun SelectionSort( data :  IntArray ){
	var length : Int = data.size
	for( i in length = 1 downTo 0){
		var max : Int = i
		for( j in 0 until i ){
			if( data[j] > data[max] )
				max = j
		}
		Swap ( data, i, max )
	}
} 
