// For(int j = 0; j < N; j++) {
// 	for(int I = 1; I <= W; i++) {
// 		if(I – weight[j] >= 0){
// 			d[i][j] = max(d[i][j -1], d[I – weight[i]][j – 1] + value[j])
// 		}	
// 		else {
// 			d[i][j] = d[i][j – 1]
// 		}
// 	}
// }
// DP[i][j] = max(DP[i][j-1], DP[I – weight[j]][j - 1] + value[j])