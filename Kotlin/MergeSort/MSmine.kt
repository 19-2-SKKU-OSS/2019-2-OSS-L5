package sort

fun main(args: Array<String>){
    val array = mutableListOf(24, 3, 5, 19, 200, 51)
    
    val sorted_array = merge_sort(array)
    print("sorted array = $sorted_array")

}

fun merge_sort(array: MutableList<Int>): MutableList<Int> {
    val len = array.size
    if(len<=1) return array

    val mid = len/2
    val left = merge_sort(array.subList(0,mid))
    val right = merge_sort(array.subList(mid, len))

    return merge(left, right)

}

fun merge(left: MutableList<Int>, right: MutableList<Int>): MutableList<Int>{
    val result = mutableListOf<Int>()
    var lfidx=0
    var riidx=0

    while(lfidx<left.size && riidx<right.size){
        val lh=left[lfidx]
        val rh=right[riidx]
        if(lh<rh){
            result.add(lh)
            lfidx++}
        else{
            result.add(rh)
            riidx++}
    }

    while(lfidx<left.size){
        result.add(left[lfidx])
        lfidx++
    }
    while(riidx<right.size){
        result.add(right[riidx])
        riidx++
    }

    return result
}

