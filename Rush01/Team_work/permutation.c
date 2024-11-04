void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *arr, int start, int end, char **result, int *count) {
    if (start == end) {
        result[*count] = arr;
        (*count)++;
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&arr[start], &arr[i]);
        permute(arr, start + 1, end, result, count);
        swap(&arr[start], &arr[i]);
    }
}

char **generatePermutations(char *arr, int n, int *count) {
    *count = 0;
    char **result = (char **)malloc(sizeof(char *) * 24);

    permute(arr, 0, n - 1, result, count);

    return result;


int main() {
    char arr[] = "1234";
    int n = sizeof(arr) - 1;
    int count = 0;

    char **permutations = generatePermutations(arr, n, &count);

    // Use the permutations array as needed

    // Free the memory allocated for the permutations array
    for (int i = 0; i < count; i++) {
        free(permutations[i]);
    }
    free(permutations);

    return 0;
}