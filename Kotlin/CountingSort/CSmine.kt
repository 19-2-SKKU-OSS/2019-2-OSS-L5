package sort

fun main(args: Array<String>){
    val array: Array<Int> = arrayOf(24, 3, 5, 19, 200, 51)
    val cntArray = IntArray(if(array.max()==null) 0 else array.max()!! +1)

    for(num in array){
        cntArray[num]++
    }

    var current=0
    for(idx in 0 until cntArray.size){
        val value = idx
        val Occurence = cntArray[idx]
        if(Occurence>0)
            repeat(Occurence){
                array[current++]=value}
    }
    
    print("sorted array = ${array.asList()}")
}
