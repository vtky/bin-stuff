int main(int argc, char **argv, char** envp)
{
	char** env;

	for (env = envp; *env != 0; env++)
	{
		char* myEnv = *env;
		printf("%s  --->  %p\n", myEnv, env);
	}
	
	return(0);
}