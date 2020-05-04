solve :: Int -> Int
solve n = 
    f - s
    where
        f = 2^n + sum [2^k | k <- [1 .. (div n 2 - 1)]]
        s = sum [2^k | k <- [div n 2 .. n - 1]]


handle_tests :: Int -> IO()
handle_tests 0 = do return ()
handle_tests t = do
    n <- getLine  
    print . solve . read $ n
    handle_tests $ t - 1


main = do
    t <- getLine
    handle_tests (read t)
