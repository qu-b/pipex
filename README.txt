----------------------- Pipe Redirections -----------------------

dup2(fdin, STD_IN);				[fdin copied into STD_IN]
dup2(fdout, STD_OUT);			[fdout into STD_OUT]

pipe(pipefd);					[pipe is opened]

-> Child
close(pipefd[0]);				[pipe read closed]
dup2(pipefd[1], STD_OUT);		[write copied into STD_OUT]

								STD_IN				fdin
								STD_OUT				pipefd[1]

exec(cmd1);						executes program on STD_IN
								outputs result to STD_OUT

-> Parent
close(pipefd[1]);				[pipe write closed]
dup2(pipefd[0], STD_IN);		[read copied into STD_IN]

								STD_IN				pipefd[0]
								STD_OUT				fdout

waitpid(child);					waits for program to finish executing
exec(cmd2);						executes 2nd program on STD_IN 
								(which is the output of prgram 1)
								outputs to fdout

------------------------------ Bonus ------------------------------

							redirect (1)
-> Child
close(pipefd[0]);				[pipe 'read' closed]
dup2(pipefd[1], STD_OUT);		['write' copied into STD_OUT]

								STD_IN				fdin
								STD_OUT				pipefd[1]

-> Parent
close(pipefd[1]);				[pipe 'write' closed]
dup2(pipefd[0], STD_IN);		['read' copied into STD_IN]

								STD_IN				(0)pipefd[0]
								STD_OUT				fdout


							redirect (2)
-> Child
close(pipefd[0]);				[pipe 'read' closed]
dup2(pipefd[1], STD_OUT);		['write' copied into STD_OUT]

								STD_IN				(0)pipefd[0]
								STD_OUT				pipefd[1]

-> Parent
close(pipefd[1]);				[pipe 'write' closed]
dup2(pipefd[0], STD_IN);		['read' copied into STD_IN]

								STD_IN				pipefd[0]
								STD_OUT				fdout