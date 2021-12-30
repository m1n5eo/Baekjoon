#include <bits/stdc++.h>
using namespace std;

char ch[103];

int main() {
	int i = 0;
	scanf("%s", ch);
	while(ch[i] != '.') i++;
	i++;
	
	if(ch[i] == 'p' && ch[i+1] == 'p' && ch[i+2] == 't' && ch[i+3] == 'x' && ch[i+4] == 'm') printf("powerpointxmlfile");
	else if(ch[i] == 'p' && ch[i+1] == 'p' && ch[i+2] == 't' && ch[i+3] == 'x') printf("PowerPoint.Show.12");
	else if(ch[i] == 'p' && ch[i+1] == 'p' && ch[i+2] == 't') printf("PowerPoint.Show.8");
	else if(ch[i] == 'j' && ch[i+1] == 'p' && ch[i+2] == 'e') printf("jpegfile");
	else if(ch[i] == 'j' && ch[i+1] == 'p' && ch[i+2] == 'g') printf("jpegfile");
	else if(ch[i] == 'h' && ch[i+1] == 'w' && ch[i+2] == 't') printf("Hwp.Document.hwt.96");
	else if(ch[i] == 'h' && ch[i+1] == 'w' && ch[i+2] == 'p' && ch[i+3] == 'x') printf("Hwp.Document.hwpx.96");
	else if(ch[i] == 'h' && ch[i+1] == 'w' && ch[i+2] == 'p') printf("Hwp.Document.96");
	else if(ch[i] == 'h' && ch[i+1] == 't' && ch[i+2] == 'm' && ch[i+3] == 'l') printf("htmlfile");
	else if(ch[i] == 'h' && ch[i+1] == 't' && ch[i+2] == 'm') printf("htmfile");
	else if(ch[i] == 'd' && ch[i+1] == 'o' && ch[i+2] == 'c' && ch[i+3] == 'x') printf("Word.Document.12");
	else if(ch[i] == 'd' && ch[i+1] == 'o' && ch[i+2] == 'c') printf("Word.Document.8");
	else if(ch[i] == 'd' && ch[i+1] == 'i' && ch[i+2] == 'b') printf("Paint.Picture");
}