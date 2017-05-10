/**
 *  UI
 *  Yimin Xu 250876566
 */
import java.util.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;;

public class UI 
{	
	public static void main(String[] args)  
	{
		File f = new File(args[0]);
		
		BufferedReader reader;
		//Insert the data in the text file into the dictionary 
		try 
		{
			reader = new BufferedReader(new FileReader(f));
			OrderedDictionary dict = new OrderedDictionary();
			String name;

			
			while ((name = reader.readLine()) != null)
			{
				String data = reader.readLine();
				int type;
			
				if (data.endsWith(".gif") || data.endsWith(".jpg")) 
					type = 3;
				else if (data.endsWith(".wav") || data.endsWith(".mid"))
					type = 2;
				else
					type = 1;
				Key k = new Key(name,type);
				dict.insert(new Record(k,data));
			}
			
			//Read the input command 
			StringReader keyboard = new StringReader();
			String line = keyboard.read("Enter next command or 'end' to quit: ");
			{
				while (!line.equals("end"))
				{
					StringTokenizer s = new StringTokenizer(line," ");
					String comType = s.nextToken();
					
					if (comType.equals("search")) //Input format: "search keyword"
					{
						//If there are more than one records with keys that have same name, get all of them
						String word = s.nextToken();
						Key k1 = new Key(word,1);
						Key k2 = new Key(word,2);
						Key k3 = new Key(word,3);
						
						if (dict.find(k1) == null && dict.find(k2) == null && dict.find(k3) == null) //If the target is not found, print out "target not found"
							System.out.println("Target not found");
						if (dict.find(k1) != null)
							System.out.println(dict.find(k1).getData());
						if (dict.find(k2) != null)
						{
							SoundPlayer sound = new SoundPlayer();
							sound.play(dict.find(k2).getData());
						}
						if (dict.find(k3) != null)
						{
							PictureViewer picture = new PictureViewer();
							picture.show(dict.find(k3).getData());
						}
					}
					
					else if (comType.equals("remove")) //Input format: "remove key_word key_type"
					{
						String word = s.nextToken();
						int type = Integer.parseInt(s.nextToken());
						Key nKey = new Key(word,type);
						dict.remove(nKey);
					}
					
					else if (comType.equals("insert")) //Input format: "insert key_word key_type data_name"
					{
						String word = s.nextToken();
						int type = Integer.parseInt(s.nextToken());
						String data = s.nextToken();
						Key nKey = new Key(word,type);
						Record r = new Record(nKey,data);
						dict.insert(r);
					}
					
					else if (comType.equals("next")) //Input format: "next key_word key_type"
					{
						String word = s.nextToken();
						int type = Integer.parseInt(s.nextToken());
						Key nKey = new Key(word,type);
						Record target = dict.successor(nKey);
						System.out.println(target.getKey().getWord() + "," + target.getKey().getType());
					}
					
					else if (comType.equals("prev")) //Input format: "prev key_word key_type"
					{
						String word = s.nextToken();
						int type = Integer.parseInt(s.nextToken());
						Key nKey = new Key(word,type);
						Record target = dict.predecessor(nKey);
						System.out.println(target.getKey().getWord() + "," + target.getKey().getType());
					}
					
					else if (comType.equals("first")) //Input format: "first"
					{
						System.out.println(dict.smallest());
					}
					
					else if (comType.equals("last")) //Input format: "last"
					{
						System.out.println(dict.largest()); 
					}
					
					else 
					{
						System.out.println("Invalid input");
						break;
					}
					line = keyboard.read("Enter next command or 'end' to quit: ");
				}
			}
		}
		
		//Handle the exceptions
		catch(FileNotFoundException e)
		{
			System.out.println("File not found");
		}
		catch (DictionaryException e)
		{
			System.out.println("Something wrong with dictionary.");
		}
		
		catch (NoSuchElementException e)
		{
			System.out.println("Something is wrong with string tokenizer.");
		} 
		catch (MultimediaException e) 
		{
			System.out.println("Something wrong with the media.");
		}
		catch (Exception e)
		{
			System.out.println("Something is wrong.");
		}
	}
}
