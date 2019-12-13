package sort

fun main(args: Array<String>){
    val array: Array<Int> = arrayOf(24, 3, 5, 19, 200, 51) //array to sort 정렬할 배열
    val cntArray = IntArray(if(array.max()==null) 0 else array.max()!! +1) //array to count 갯수 셀 배열

    for(num in array){
        cntArray[num]++ //count the number of value 해당 값의 갯수 세기
    }

    var current=0
    for(idx in 0 until cntArray.size){ //change original array to sorted array 원래 배열을 정렬한 배열로
        val value = idx
        val Occurence = cntArray[idx]
        if(Occurence>0)
            repeat(Occurence){
                array[current++]=value}
    }
    
    print("sorted array = ${array.asList()}") //print out 배열 출력
}
