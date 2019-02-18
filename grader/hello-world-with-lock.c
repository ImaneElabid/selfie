// global variable for pointing to the "Hello World!    " string
uint64_t* foo;

// main procedure for printing "Hello World!    " on the console
uint64_t* main() {
  // create 2^4 processes
  fork();
  fork();
  fork();
  fork();


  // point to the "Hello World!    " string
  foo = "Hello World!    ";

  // strings are actually stored in chunks of 8 characters in memory,
  // that is, here as "Hello Wo", and "rld!    " which allows us to
  // print them conveniently in chunks of 8 characters at a time

  flock(1,2); //LOCK_EX        2         /* Exclusive lock.  */

  // as long as there are characters print them
  while (*foo != 0) {
    // 1 means that we print to the console
    // foo points to a chunk of 8 characters
    // 8 means that we print 8 characters
    write(1, foo, 8);

    // go to the next chunk of 8 characters
    foo = foo + 1;
  }

  flock(1,8); //LOCK_UN        8        /* Unlock.  */
}
