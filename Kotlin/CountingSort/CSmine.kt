package sort

fun main(args: Array<String>){
    val array: Array<Int> = arrayOf(24, 3, 5, 19, 200, 51) //array to sort
    val cntArray = IntArray(if(array.max()==null) 0 else array.max()!! +1) //array to count

    for(num in array){
        cntArray[num]++ //count the number of value
    }

    var current=0
    for(idx in 0 until cntArray.size){ //change original array to sorted array
        val value = idx
        val Occurence = cntArray[idx]
        if(Occurence>0)
            repeat(Occurence){
                array[current++]=value}
    }
    
    print("sorted array = ${array.asList()}") //print out
}
