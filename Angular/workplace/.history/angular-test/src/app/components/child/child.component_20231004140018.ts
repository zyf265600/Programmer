import { AfterContentInit, AfterViewChecked, AfterViewInit, Component, Input, OnChanges, OnInit, SimpleChanges } from '@angular/core';

@Component({
  selector: 'app-child',
  templateUrl: './child.component.html',
  styleUrls: ['./child.component.css']
})
export class ChildComponent implements OnInit, AfterContentInit, AfterViewInit, OnChanges{
  @Input("name") name: string = ""

  constructor() { 
    console.log("ChildComponent constructor");
  }
  ngOnChanges(changes: SimpleChanges): void {
    cons
  }

  ngOnInit(): void {
    console.log("ChildComponent ngOnInit");
  }

  ngAfterContentInit(): void {
    console.log("ChildComponent ngAfterContentInit");
  }

  ngAfterViewInit(): void {
    console.log("ChildComponent ngAfterViewInit");
  }
}
