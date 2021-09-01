ll N; // Given Set
ll subset_of_N = N;
while(subset_of_N)
{
    cout << subset_of_N << " ";
    subset_of_N = (subset_of_N - 1) & N;
}
// It will generate all subsets of N, (except 0)