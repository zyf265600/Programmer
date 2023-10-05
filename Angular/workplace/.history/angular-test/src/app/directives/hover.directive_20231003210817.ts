import { AfterViewInit, Directive, ElementRef, Input } from '@angular/core';

interface Options{

}

@Directive({
  selector: '[appHover]'
})
export class HoverDirective implements AfterViewInit{
  @Input("appHover") appHover: Options;
  element: HTMLElement;

  constructor(private elementRef: ElementRef) {
    this.element = elementRef.nativeElement;
  }

  ngAfterViewInit(): void {
    this.element.style.backgroundColor = 'red';
  }

}
