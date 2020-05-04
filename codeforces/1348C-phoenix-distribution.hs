import qualified Data.List as L

readInts :: IO [Int]
readInts = do
    line <- getLine
    return $  map read . words $ line

-- I'm so sorry for this, I'm still learning haskell >.<
solve :: Int -> Int -> Int -> String -> String
solve 0 _ _ _ = []
solve _ 1 _ s = s
solve n k d s
    | (not uniformCur && d == 0) = [letter]
    | ((d /= 0 && hypothesis /= s) || not uniformCur && d /= 0) = solve n 1 (d + 1) s
    | (uniformCur && d == 0) = (letter : (solve n' k (d + 1) $ rem))
    | otherwise = take (div (n + k - 1) k) s
    where
        hypothesis = replicate n letter
        uniformCur = (cur == take (n - n') hypothesis)
        cur = take k s
        rem = drop k s
        n' = length rem
        letter = maximum cur
    
handleTest :: Int -> IO ()
handleTest 0 = return ()
handleTest t = do 
    [n, k] <- readInts
    s <- getLine
    putStrLn $ solve n k 0 $ L.sort s
    handleTest $ t - 1


main = do
    t <- getLine
    handleTest $ read t
