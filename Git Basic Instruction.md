git init						//to initialize git
git add .						// To add all files in the branch/directory to git
git commit -m "my commit"		//To commit to local repository 

**** Origin:main branch in github **** master: main branch in local machine *****

*************To set target repository (Origin)***********

git remote add origin git@github.com:josexavier06/repo_name.git
git remote set-url origin git@github.com:josexavier06/repo_name.git


git pull  /***** To fetch and merge files from origin to master
git push origin master   /*** To push files from master to origin
git push -f  /* brute force*/
	
************To roll back to particular commit************
	git reset --hard <old-commit-id>	
		git push -f

****** Clone *****************
git clone [SSH-URL] [FOLDER-NAME] 	// To make a copy of origin in ur local machine
cd [FOLDER-NAME] // TO switch to the cloned directory

************* To work branch ********************
git checkout -b [branch-name]	//To make a new branch
git checkout [branch-name] 		//To switch to an existing directory
