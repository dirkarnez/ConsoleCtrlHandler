https://github.com/stm32duino/stm32flash/blob/main/main.c

#if defined(__WIN32__) || defined(__CYGWIN__)
	SetConsoleCtrlHandler( (PHANDLER_ROUTINE) CtrlHandler, TRUE );
#else
	struct sigaction sigIntHandler;

	sigIntHandler.sa_handler = sighandler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;

	sigaction(SIGINT, &sigIntHandler, NULL);
#endif
