/**
 * Key
 * @author Yimin Xu 250876566
 *
 */
public class Key 
{
	private String keyWord;
	private int keyType;
	
	// Constructor
	public Key(String word, int type)
	{
		keyWord = word.toLowerCase();
		keyType = type;
	}
	
	// Return the word of key
	public String getWord()
	{
		return keyWord;
	}
	
	// Return the type of key 
	public int getType()
	{
		return keyType;
	}
	
	// Compare the key
	public int compareTo(Key k)
	{
		if ((keyWord.equals(k.getWord())) && (keyType == k.getType()))
			return 0;
		else if (keyWord.compareTo(k.getWord()) < 0)
			return -1;
		else if ((keyWord.equals(k.getWord()) && keyType < k.getType()))
			return -1;
		else
			return 1;
	}
}
