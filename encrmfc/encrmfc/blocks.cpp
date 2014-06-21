/*#include "blocks.h"

void blocks()
{
	static int inlen;
	byte *in, *out, *buf;
	int blocksize = 16;
	buf = new byte[blocksize-1];
	int outlen;

	FILE* f;
	
	f = fopen ("../../tex.txt","r");
	
	if (f) 
	{
	fseek (f, 0, SEEK_END);
	inlen = ftell (f);
	rewind (f);

	outlen  = inlen + (inlen+1)%16;
	in = new byte[inlen];
	out = new byte[outlen];

	fread (in, sizeof(char), 0, f);
	
	for (int i=0; i<inlen; i++)   // записываю текст в аут
	{
		fread(&(out[i]), sizeof(char), 1, f);
		cout<<out[i];
	}

	memset (out+inlen, '/0', outlen-inlen); // зануление последних элементов

	cout<<"\n"<<"\n";

	fclose (f);
	}
	else
	{
		cout<<"Empty stream"<<"\n";
	}

	for ( int k = 0; k<(outlen/blocksize); k++ )
	{
	memcpy(buf, out + k*blocksize, blocksize);
	

	for (int j = 0; j < blocksize; j++)
	{
		cout<<buf[j];
	}
	cout<<"\n";
	}                              // конец деления на блоки

	/* PBKDF2
	byte *derived,            
	size_t derivedLen,     
	byte purpose,            
	const byte *password, 
	size_t passwordLen, 
	const byte *salt, 
	size_t saltLen, 
	unsigned int iterations, 
	double timeInSeconds=0
	



	//system("pause");
}*/