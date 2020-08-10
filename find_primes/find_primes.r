#' Find prime numbers
#' 
#' Search for prime numbers in a range from `start` to `end`.
#' 
#' The search range can be specified either as command line arguments,
#' where the first arguement is start and the second is end. If no
#' command line arguements are provided, the user is prompted to 
#' provide start and end integers.
main <- function() {
    argv <- commandArgs(trailingOnly = TRUE)
    
    if (length(argv) == 0) {
        # Prompt user for search range if not provided as command
        # line arguements
        start <- get_number("Enter a starting number: ")
        end <- get_number("Enter an ending number: ")
    } else if (length(argv) == 2) {
        # Parse command line arguements if exactly 2 trailing are provided
        if (!all(grepl("^[0-9]+$", argv))) {
            stop("Usage: Rscript find_primes.R [start] [end]", call. = FALSE)
        } else {
            start <- argv[1]
            end   <- argv[2]
        }

    } else {
        # Throw error if > 0 and != 2 command line arguements are provided
        stop("Usage: Rscript find_primes.R [start] [end]", call. = FALSE)
    }

    if (start < 1 | end < 1) {
        stop("Start and end must be positive integers", call. = FALSE)
    }
    if (end < start) {
        stop("Error: End must be greater than start", call. = FALSE)
    }

    if (start < 2) {
        start = 2
    }

    cat("Prime numbers between ", start, " and ", end, ":\n", sep = "")
    primes = c()
    
    for (n in seq(start, end)) {
        prime_flag = 1
        for (x in seq(2, n )) {
            if (n %% x == 0 & n != x) {
                prime_flag = 0
                break
            } 
        }
        if (prime_flag == 1) {
            primes = c(primes, n)
        }
    }

    for (i in primes) {
        cat(i, end = "\n")
    }
}

#' Get an integer from the user
#' 
#' Prompts the user for an integer value
#' 
#' @param prompt a string to display to the user as a prompt
#' @return an integer
get_number <- function(prompt) {
    num = ''
    while(is.character(num)) {
        cat(prompt);
        num <- readLines("stdin", n=1)

        if (grepl("^[0-9]+$", num)) {
            num <- as.integer(num)
        }
    }
    return(num)
}

main()