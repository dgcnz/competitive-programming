import qualified Data.Set as S
import qualified Data.List as L

readInts :: IO [Int]
readInts = do
    input <- getLine
    return $ map read . words $ input
  
printAnswer :: [Int] -> IO ()
printAnswer [] = putStrLn "-1"
printAnswer ans = do
    print $ length ans
    putStrLn . unwords $ map show ans

solve :: [Int] -> Int -> Int -> [Int]
solve unique n k
    | len > k = []
    | otherwise = take (n * k) $ L.cycle unique'
    where
        len = length unique
        unique' = L.replicate (k - len) 1 ++ unique
    
handle_test :: Int -> IO()
handle_test 0 = do return ()
handle_test t =  do
    [n, k] <- readInts
    a <- readInts
    let unique = S.toList (S.fromList a) in
        printAnswer $ solve unique n k
    handle_test $ t - 1

main = do
    t <- getLine
    handle_test $ read t
