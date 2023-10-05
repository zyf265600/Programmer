import { AfterViewInit, Directive, ElementRef } from '@angular/core';

@Directive({
  selector: '[appHover]'
})
export class HoverDirective implements AfterViewInit{

  element: ElementRef;

  constructor(private elementRef: ElementRef) {
    console.log(this.elementRef);
  }

  ngAfterViewInit(): void {

    this.elementRef.nativeElement.style.backgroundColor = 'red';
  }

}
