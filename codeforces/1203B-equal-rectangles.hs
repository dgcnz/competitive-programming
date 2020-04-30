import qualified Data.List as L

readInts :: IO [Int]
readInts = do
    input <- getLine
    return $ map read . words $ input

splitOnHalf :: [a] -> ([a], [a])
splitOnHalf xs = (take half xs, drop half xs)
    where half = div (length xs) 2

equalArea :: [Int] -> [Int] -> Int -> Bool

equalArea [] [] _ = True
equalArea (x1:x2:xs) (y1:y2:ys) area = 
    x1 == x2 && y1 == y2 && (x1 * y2) == area && equalArea xs ys area

solve :: [Int] -> Bool
solve xs = 
    equalArea s b' $ (head s) * (head b')
    where 
        b' = reverse b
        (s, b) = splitOnHalf xs

handleCase :: Int -> IO ()

handleCase 0 = do return ()
handleCase t = do
    n <- getLine
    a <- readInts
    putStrLn $ if solve(L.sort a) == True then "YES" else "NO"
    handleCase(t-1)

main = do
    t <- getLine 
    handleCase (read t)
