import java.util.Arrays;

/**
 * Created: 9/5/24
 *
 * @author lsdevcloud (lsdevcloud@lsdevcloud.com)
 */
public class BubbleSort {

    public static void main(String[] args) {

        final int[] unsorted = { 666, 6, 9, 420, 80085 }; // array to be sorted
        final int[] sorted = bubbleSort(unsorted); // sorted array

        Arrays.stream(sorted).forEach(System.out::println);
    }

    public static int[] bubbleSort(int[] toSort) {
        int t; // temp
        for (int i = 1; i < toSort.length; i++) {
            for (int j = 0; j < toSort.length - i; j++) {
                if (toSort[j] > toSort[j + 1]) {
                    t = toSort[j];
                    toSort[j] = toSort[j + 1];
                    toSort[j + 1] = t;
                }
            }
        }
        return toSort;
    }
}