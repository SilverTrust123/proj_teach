package B11221009;
import java.security.SecureRandom;
class Craps {
    private SecureRandom randomNumbers = new SecureRandom();
    public int play() {
        int dice1 = 1 + randomNumbers.nextInt(6);
        int dice2 = 1 + randomNumbers.nextInt(6);
        int sum = dice1 + dice2;
        int rollCount = 1;
        switch (sum) {
            case 7:
            case 11:
                return rollCount;
            case 2:
            case 3:
            case 12:
                return -rollCount; 
            default:
                int point = sum;
                while (true) {
                    dice1 = 1 + randomNumbers.nextInt(6);
                    dice2 = 1 + randomNumbers.nextInt(6);
                    rollCount++;

                    if (dice1 + dice2 == point) {
                        return rollCount; 
                    } else if (dice1 + dice2 == 7) {
                        return -rollCount; 
                    }
                }
        }
    }
}