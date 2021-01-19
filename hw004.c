#include <stdio.h>

int plan183(int inNet, int outNet, int land, int inSMS, int outSMS){
	if(inNet*0.08 + outNet*0.1393 + land*0.1349 + inSMS*1.1287 + outSMS*1.4803<183)
		return 183;
	else
		return inNet*0.08 + outNet*0.1393 + land*0.1349 + inSMS*1.1287 + outSMS*1.4803;
}
int plan383(int inNet, int outNet, int land, int inSMS, int outSMS){
	if(inNet*0.07 + outNet*0.1304 + land*0.1217 + inSMS*1.1127 + outSMS*1.2458<383)
		return 383;
	else
		return inNet*0.07 + outNet*0.1304 + land*0.1217 + inSMS*1.1127 + outSMS*1.2458;
}
int plan983(int inNet, int outNet, int land, int inSMS, int outSMS){
	if(inNet*0.06 + outNet*0.1087 + land*0.1018 + inSMS*0.9527 + outSMS*1.1243<983)
		return 983;
	else
		return inNet*0.06 + outNet*0.1087 + land*0.1018 + inSMS*0.9527 + outSMS*1.1243;
}

int main(){
	int inNet, outNet, land, inSMS, outSMS;
	scanf("%d%d%d%d%d", &inNet, &outNet, &land, &inSMS, &outSMS);
	int result183 = plan183(inNet, outNet, land, inSMS, outSMS);
	int result383 = plan383(inNet, outNet, land, inSMS, outSMS);
	int result983 = plan983(inNet, outNet, land, inSMS, outSMS);
	if(result183<result383 && result183<result983){
		printf("183型\n");
	} else if(result383<result183 && result383<result983){
		printf("383型\n");
	} else {
		printf("983型\n");
	}
	return 0;
}
