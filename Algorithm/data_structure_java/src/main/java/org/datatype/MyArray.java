package org.datatype;

public class MyArray {
    public static void main(String args[]){
        declare();

        int[] arr = new int[]{1,2,3,4,6,7,8,9,10,0};
        System.out.print("arr value:        ");
        print(arr);

        insert(arr, 9, 11);
        System.out.print("inserted arr value:    ");
        print(arr);

        delete(arr, 10, 11);
        System.out.print("deleted arr value:    ");
        print(arr);
    }

    public static void delete(int[] arr, int size, int num){
        if (arr.length==0 || arr.length < size) return;

        int index=-1;
        for (int i=0; i < arr.length; i++){
            if (arr[i] == num) index=i;
        }

        if (index!=-1){
            for (int i=index; i<arr.length-1; i++){
                arr[i] = arr[i+1];
            }
            arr[size-1] = 0;
        }
    }

    // size: number of existed num in the array
    public static void insert(int[] arr, int size, int num){
        if (arr.length == 0 || arr.length <= size) return;

        int index = size;
        for (int i=0; i < arr.length; i++){
            if (arr[i] > num){
                index = i;
                break;
            }
        }
        for (int i=size; i>index; i--){
            arr[i] = arr[i-1];
        }
        arr[index] = num;
    }

    public static void declare(){
        System.out.println("Array:");

        System.out.print("arr1 length: ");
        int[] arr1 = new int[10];
        System.out.println(arr1.length);

        int[] arr2 = new int[]{1,2,3,4,5};
        for (int i=0; i<arr2.length; ++i){
            System.out.print(arr2[i] + " ");
        }
        System.out.println();

        int[] arr3 = {5,6,7,8,9};
        for(int i=0; i<arr3.length; ++i){
            System.out.print(arr3[i] + " ");
        }
        System.out.println();

        int[] a = new int[]{1,2,3};
        int[] b = new int[10];
        int[] c = {1,2,3,4};
    }

    public static void print(int[] arr){
        for (int i=0; i<arr.length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
