import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-child',
  templateUrl: './child.component.html',
  styleUrls: ['./child.component.css']
})
export class ChildComponent implements OnInit{
  constructor() { 
    console.log("ChildComponent constructor");
  }
  
  ngOnInit(): void {
    throw new Error('Method not implemented.');
  }

}
