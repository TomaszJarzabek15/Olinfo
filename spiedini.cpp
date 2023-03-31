int zeriDestra, totDestra, zeriSinistra, totSinistra;

 int solve(int N, int K, int s[]) {
 // inizialmente, supponiamo di aver mangiato tutto da destra
 	for(int i=0; i<N; i++) {
 		if (s[i] == 0)
 			zeriDestra++;
 		totDestra += s[i];
 	}
 	int p1 = 0; // puntatore sinistro
 	int p2 = 0; // puntatore destro
 	int risposta = 0;
 	while (p1<N) {
 		// finche’ ho mangiato troppo, mangio un frutto in meno da destra
 		while (p2<N && totSinistra+totDestra>K) {
 			if(s[p2] == 0)
 				zeriDestra--;
 			totDestra -= s[p2++];
 		}
 		// se a destra mangio 0 frutti ma mangio comunque troppo, allora esci
 		if (p2==N && totSinistra+totDestra>K)
 			break;
 		// ho trovato una coppia di indici candidata per essere quella ottimale
 		if (p1<=p2 && zeriDestra+zeriSinistra>risposta)
 			risposta = zeriDestra+zeriSinistra;
 		// mangio un frutto in piu’ da sinistra alla prossima iterazione
 		if (s[p1] == 0)
 			zeriSinistra++;
 		totSinistra += s[p1++];
 	}
 	return risposta;
 }
