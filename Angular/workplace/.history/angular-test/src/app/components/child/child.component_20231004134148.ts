import { AfterContentInit, Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-child',
  templateUrl: './child.component.html',
  styleUrls: ['./child.component.css']
})
export class ChildComponent implements OnInit, AfterContentInit{
  constructor() { 
    console.log("ChildComponent constructor");
  }

  ngOnInit(): void {
    console.log("ChildComponent ngOnInit");
  }

  ngAfterContentInit(): void {
    throw new Error('Method not implemented.');
  }


}
