# Urlsniff

A URL fetcher with endless possibilities.

![Urlsniff](https://raw.githubusercontent.com/sebinbabu/urlsniff/master/urlsniff.jpg)


### Prerequisites

You need to install the following two packages: 
* curl / libcurl : Developer’s libraries for curl

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. Open up your terminal after installing the prerequisites and put these commands.

```
git clone https://github.com/sebinbabu/urlsniff.git
cd urlsniff
make
sudo make install
```
## Usage

Use the ```urlsniff help``` command to get instructions.

#### Example usage (and proof of endless possibilities)

* ```urlsniff https://google.com``` : grabs all URLs from google.com
* ```urlsniff https://google.com > links.txt``` : grabs all URLs from google.com and saves into links.txt
* ```urlsniff < links.txt``` : grabs all URLs from the URLs inside links.txt
* ```urlsniff https://google.com | urlsniff``` : recursively grabs all URLs from google.com (might fall into a deadloop)
* ```urlsniff https://google.com | grep books | urlsniff``` : grabs all URLs from the URLs grabbed google.com that contain the word 'books'

I mean come on, the last example must have blown your mind. Mine did too! Just look at the beauty of it. Like I said, endless possibilities...

## Authors / Credits

* **Sebin Babu** - *Initial work* - [Sebin Babu](https://github.com/sebinbabu)

## License

This project is licensed under the Apache 2.0 License - see the [LICENSE.md](LICENSE.md) file for details

