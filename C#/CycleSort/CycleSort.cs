using System;

class Programm{

	public static void CycleSort(int* array, int length){
		int cycle_start, element, index, tmp;

		for( cycle_start = 0; cycle_start < length - 1; cycle_start++ ){
			element = array[cycle_start];
			index = cycle_start;

			for( int i = cylce_start + 1; i < length; i++ ){
				if( array[i] < element )index++;
			}
			if( index == cycle_start )continue;

			while( element == array[index] ) index++;
			tmp = array[index];
			array[index] = element;
			element = tmp;

			while( index != cycle_start ){
				index = cycle_start;

				for( int i = cycle_start + 1; i < length; i++ ){
					if( array[i] < element ) index++;
				}
		
				while( element == array[index] ) index++;
				tmp = array[index];
				array[index] = element;
				element = tmp;
			}
		}
	}
}
