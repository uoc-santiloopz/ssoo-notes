int main() {
	int state, fileDesc, pid;
	// ...
	pid = fork();

	switch(pid) {
		case 0:
			// child process code
			fileDesc = open("file", O_RDONLY);
			if (fileDesc == -1){
				// handle error
			}
			// ...
			close(0);
			dup(fileDesc);
			close(fileDesc);
			// ...
			execl("/bin/command","command",0);
			// ...
			// handle error
			// ...
		case -1:
			// fork failed
			// ...
			// handle error
			// ...
		default:
			// parent code
			while(pid != wait(&state));
	}
}